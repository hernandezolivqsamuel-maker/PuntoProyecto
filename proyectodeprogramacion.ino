/*
==================================================
PROYECTO:
LENTES INTELIGENTES PARA PERSONAS INVIDENTES
==================================================
Josue Braulio Ravelo López
Nancy Cristal Largo Muñoz
Samuel Hernandez Oliva

Funciones:
- Detecta obstáculos altos con sensores en lentes
- Detecta obstáculos bajos con sensor en bastón
- Alerta mediante vibración y buzzer
- Usa Programación Orientada a Objetos
- Implementa SOLID y Factory Method
==================================================
*/

// ==================================================
// PINES
// ==================================================

// Sensor lentes
#define TRIG_LENTES 2
#define ECHO_LENTES 3

// Sensor bastón
#define TRIG_BASTON 4
#define ECHO_BASTON 5

// Actuadores
#define BUZZER_PIN 8
#define VIBRADOR_PIN 9

// ==================================================
// INTERFAZ SENSOR
// ABSTRACCIÓN
// ==================================================

class ISensor {

  public:

    virtual float leerDistancia() = 0;
};

// ==================================================
// SENSOR ULTRASONICO
// HERENCIA
// ==================================================

class SensorUltrasonico : public ISensor {

  private:

    int trigPin;
    int echoPin;

  public:

    SensorUltrasonico(int trig, int echo) {

      trigPin = trig;
      echoPin = echo;

      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    // POLIMORFISMO
    float leerDistancia() override {

      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);

      digitalWrite(trigPin, LOW);

      long duracion = pulseIn(echoPin, HIGH);

      float distancia = duracion * 0.034 / 2;

      return distancia;
    }
};

// ==================================================
// INTERFAZ ACTUADOR
// ==================================================

class IActuador {

  public:

    virtual void activar() = 0;
    virtual void desactivar() = 0;
};

// ==================================================
// CLASE BUZZER
// ==================================================

class Buzzer : public IActuador {

  private:

    int pin;

  public:

    Buzzer(int p) {

      pin = p;

      pinMode(pin, OUTPUT);
    }

    void activar() override {

      tone(pin, 1000);
    }

    void desactivar() override {

      noTone(pin);
    }
};

// ==================================================
// CLASE VIBRADOR
// ==================================================

class Vibrador : public IActuador {

  private:

    int pin;

  public:

    Vibrador(int p) {

      pin = p;

      pinMode(pin, OUTPUT);
    }

    void activar() override {

      digitalWrite(pin, HIGH);
    }

    void desactivar() override {

      digitalWrite(pin, LOW);
    }
};

// ==================================================
// FACTORY METHOD
// CREA SENSORES
// ==================================================

class SensorFactory {

  public:

    static ISensor* crearSensorUltrasonico(
      int trig,
      int echo
    ) {

      return new SensorUltrasonico(
        trig,
        echo
      );
    }
};

// ==================================================
// SISTEMA DE ALERTAS
// SRP -> UNA RESPONSABILIDAD
// ==================================================

class SistemaAlerta {

  private:

    ISensor* sensorLentes;
    ISensor* sensorBaston;

    Buzzer* buzzer;
    Vibrador* vibrador;

  public:

    SistemaAlerta(
      ISensor* lentes,
      ISensor* baston,
      Buzzer* buzz,
      Vibrador* vib
    ) {

      sensorLentes = lentes;
      sensorBaston = baston;

      buzzer = buzz;
      vibrador = vib;
    }

    // FUNCION PRINCIPAL
    void verificarEntorno() {

      float distanciaLentes =
        sensorLentes->leerDistancia();

      float distanciaBaston =
        sensorBaston->leerDistancia();

      Serial.print("Distancia lentes: ");
      Serial.println(distanciaLentes);

      Serial.print("Distancia baston: ");
      Serial.println(distanciaBaston);

      // Obtener la distancia mas cercana

      float distanciaMinima;

      if (distanciaLentes < distanciaBaston) {

        distanciaMinima = distanciaLentes;
      }

      else {

        distanciaMinima = distanciaBaston;
      }

      controlarAlertas(distanciaMinima);
    }

  private:

    // ALERTAS SEGUN DISTANCIA

    void controlarAlertas(float distancia) {

      // MUY CERCA
      if (distancia <= 20) {

        vibrador->activar();

        buzzer->activar();

        delay(100);
      }

      // CERCA
      else if (distancia <= 40) {

        buzzer->desactivar();

        vibrador->activar();

        delay(200);

        vibrador->desactivar();

        delay(200);
      }

      // PRECAUCION
      else if (distancia <= 70) {

        buzzer->desactivar();

        vibrador->activar();

        delay(500);

        vibrador->desactivar();

        delay(500);
      }

      // SEGURO
      else {

        vibrador->desactivar();

        buzzer->desactivar();
      }
    }
};

// ==================================================
// OBJETOS GLOBALES
// ==================================================

ISensor* sensorLentes;
ISensor* sensorBaston;

Buzzer* buzzer;

Vibrador* vibrador;

SistemaAlerta* sistema;

// ==================================================
// SETUP
// ==================================================

void setup() {

  Serial.begin(9600);

  // FACTORY METHOD

  sensorLentes =
    SensorFactory::crearSensorUltrasonico(
      TRIG_LENTES,
      ECHO_LENTES
    );

  sensorBaston =
    SensorFactory::crearSensorUltrasonico(
      TRIG_BASTON,
      ECHO_BASTON
    );

  buzzer = new Buzzer(BUZZER_PIN);

  vibrador = new Vibrador(VIBRADOR_PIN);

  sistema = new SistemaAlerta(
    sensorLentes,
    sensorBaston,
    buzzer,
    vibrador
  );

  Serial.println("Sistema iniciado");
}

// ==================================================
// LOOP
// ==================================================

void loop() {

  sistema->verificarEntorno();

  delay(50);
}

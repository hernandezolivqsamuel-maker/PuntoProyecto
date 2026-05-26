# Sistema de Lentes Inteligentes para Personas Invidentes

Proyecto desarrollado en Arduino que ayuda a personas con discapacidad visual mediante la detección de obstáculos utilizando sensores ultrasónicos, vibración y alertas sonoras.

Integrantes

- Samuel Hernandez Oliva

- Josue Braulio Ravelo López

- Nancy Cristal Largo Muñoz

## Descripción del Proyecto

Este sistema detecta obstáculos tanto a nivel superior como inferior utilizando dos sensores ultrasónicos:

Sensor en lentes: Detecta obstáculos altos como paredes, puertas o personas.
Sensor en bastón: Detecta obstáculos bajos como escalones, banquetas u objetos en el suelo.

Dependiendo de la distancia detectada, el sistema activa:

Vibración
Buzzer (sonido)

Las alertas cambian según la cercanía del obstáculo.

## Características
- Detección de obstáculos en tiempo real
- Alertas por vibración y sonido
- Arquitectura basada en Programación Orientada a Objetos (POO)
- Uso de principios SOLID
- Implementación de Factory Method
- Código modular y escalable
## Tecnologías Utilizadas
- Arduino IDE
- C++
- Sensores ultrasónicos HC-SR04
- Motor vibrador
- Buzzer
- Componente	Cantidad
- Arduino UNO/Nano	1
- Sensor ultrasónico HC-SR04	2
- Buzzer	1
- Motor vibrador	1
- Protoboard	1
- Cables Dupont	Varios
- Fuente de alimentación	1
- Conexiones
- Sensores Ultrasónicos
- Sensor de lentes

### Pin Sensor	Arduino

- TRIG	2

- ECHO	3

## Sensor de bastón

### Pin Sensor	Arduino

- TRIG	4
  
- ECHO	5
  
##Actuadores

### Dispositivo	Pin
- Buzzer	8
  
- Vibrador	9
  
## Funcionamiento

El sistema mide constantemente la distancia usando ambos sensores ultrasónicos.

Se toma la distancia más cercana y se generan alertas según el nivel de proximidad:

Distancia	Acción

≤ 20 cm	Vibración + sonido continuo

≤ 40 cm	Vibración rápida

≤ 70 cm	Vibración lenta

> 70 cm	Sin alerta

Arquitectura del Código

Interfaces

### ISensor

Define el comportamiento general de los sensores.

### IActuador

Define el comportamiento de los actuadores.

## Clases Implementadas

SensorUltrasonico

Clase que hereda de ISensor y permite medir distancia.

Buzzer

Controla las alertas sonoras.

Vibrador

Controla las alertas de vibración.

SistemaAlerta

Gestiona toda la lógica del sistema y las alertas.

SensorFactory

Implementa el patrón Factory Method para crear sensores.

## Principios SOLID Aplicados

S — Single Responsibility Principle

Cada clase tiene una única responsabilidad.

O — Open/Closed Principle

El sistema puede ampliarse agregando nuevos sensores o actuadores sin modificar el código existente.

L — Liskov Substitution Principle

Las clases derivadas pueden sustituir a sus interfaces base.

I — Interface Segregation Principle

Las interfaces son específicas y simples.

D — Dependency Inversion Principle

El sistema depende de abstracciones (ISensor, IActuador) y no de implementaciones concretas.

## Conceptos de POO Utilizados

- Abstracción
- Herencia
- Polimorfismo
- Encapsulamiento
- Instalación
- Abrir el código en Arduino IDE.
- Conectar los componentes según las tablas anteriores.
- Seleccionar la placa Arduino correspondiente.
- Subir el código al Arduino.
- Abrir el monitor serial a 9600 baudios.
- Ejemplo de Salida en Monitor Serial
- Sistema iniciado
- Distancia lentes: 35
- Distancia baston: 60

## Posibles Mejoras Futuras

- Agregar batería recargable
- Incorporar Bluetooth
- Añadir GPS
- Integrar inteligencia artificial
- Usar sensores más precisos
- Implementar mensajes de voz

## Licencia

Proyecto desarrollado con fines educativos y de apoyo social.

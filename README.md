<h1>Bowling Game</h1>
<p>Simulación de una bolera hecha en C.</p>
<h2>Para ejecutar el programa:</h2>
<ol>
<li>Introduce en la terminal "make" para compilar. Aparecerá una animación para comenzar.</li>
  <br>
<img width="273" alt="make" src="https://github.com/marinitx/bowling/assets/123256807/b23fa652-e11b-4a72-8e1a-bc72c628c0e4">
  <br><br>
<li>Introduce "./play" para ejecutar el juego.</li>
  <br>
<img width="213" alt="./play" src="https://github.com/marinitx/bowling/assets/123256807/4b461e20-0257-4226-abf1-79f8314b6924">
  <br><br>
<li>Responde a las preguntas del juego para adaptarlo a tus preferencias.</li>
  <br>
  <img width="544" alt="Captura de pantalla 2024-02-23 a las 13 44 40" src="https://github.com/marinitx/bowling/assets/123256807/81d3b644-cc1d-49d5-9cdb-59df4078eeae">
<br><br>
</ol>

## Reglas
### Regla básicas
* Se tira 10 rondas de 2 tiradas máximo cada ronda.
* Al principio de cada ronda se colocan los 10 bolos.
* Cada bolo tirado suma un punto.

![image](https://github.com/marinitx/bowling/assets/123256807/f13e1bd3-d2db-4cd0-a669-208df9707d91)


### Tests
Se recomienda usar TDD y empezar escribiendo uno a uno los tests.  
La entrada al “algoritmo” serán el nº de bolos tirados y la salida la puntuación.  
Tests básicos:
* Tirar siempre un bolo (10 rondas x 2 tiradas = 20 tiradas => 20 bolos)
![image](https://github.com/marinitx/bowling/assets/123256807/6ffa667d-3320-4dce-b328-ed318bdc1046)


Este juego lo escribiremos por abreviar como "20x1" (<nº veces>x<nº bolos tirados>)  
    20x1 -> 20 puntos

* Tirar siempre 0 bolos:  
    20x0 -> 0 puntos

* Tirar 10 veces 3 y el resto 0:  
    10x3 & 10x0 -> 30 puntos



### Semipleno "/"
Si entre las 2 tiradas de la ronda tira los 10 bolos es un semipleno.  
Esto implica que te regalan como EXTRA para esta ronda tantos puntos como bolos tires en la siguiente TIRADA.  
Tests:
* Semipleno suma la siguiente tirada:  
    5 & 5 & 3 & 17x0 -> 16 puntos
* No semipleno si los 10 puntos no son en la misma ronda:  
    0 & 5 & 5 & 3 & 16x0 -> 13 puntos
* Semipleno SOLO suma la siguiente tirada:
    5 & 5 & 3 & 17x1 -> 33 puntos


### Pleno
Si en la primera tirada de una ronda tira los 10 bolos es un pleno. No tirará la segunda tirada de la ronda.  
Esto implica que te regalan como EXTRA para esta ronda tantos puntos como bolos tires en la siguientes 2 TIRADAS.  
Tests:
* Pleno suma los 2 siguientes tiradas:  
    10 & 3 & 2 & 16x0 -> 20 puntos
* Si los 10 son en segunda tirada es semipleno:  
    0 & 10 & 3 & 2 & 16x0 -> 18 puntos
* Pleno SOLO suma las 2 siguientes tiradas:  
    10 & 3 & 2 & 16x1 -> 36 puntos

### Regla del final
La décima ronda puede tener más tiradas para saber los puntos extra de plenos o semiplenos.  
Si haces un pleno tendrás dos lanzamientos más.  
Si haces un semipleno tendrás un lanzamiento más.  
Los bolos tirados en las rondas extra solo valen como puntos extra del pleno o semipleno no como tirada propia.  
Tests:
* Pleno en última ronda da 2 tiradas extra:  
    18x0 & 10 & 1 & 1 -> 12 puntos
* Semipleno en última ronda da 1 tirada extra:  
    18x0 & 5 & 5 & 1 -> 11 puntos
* Todas las tiradas perfectas de 10 bolos (las 10 del juego más las 2 extra) consiguiendo la puntuación máxima:
    12x10 -> 300

    
![image](https://github.com/marinitx/bowling/assets/123256807/567c9106-38b4-4ea4-9567-33a8d1be1c30)

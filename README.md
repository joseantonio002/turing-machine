# Práctica 2 Máquina de Turing

## Como usar

Se compila usando el comando `g++ main.cc turing_machine.cc transition_function.cc tape.cc utils.cc -o main`, una vez se ejecute se pedirá el nombre del fichero con la descripción de la máquina de turing y 
el nombre del fichero con las cadenas con las cuales se quiere probar la máquina

## Formato del fichero descripción de la máquina de turing

\# comentarios
conjunto de estados separados por espacios (q0 q1 q2...)
alfabeto de la cadena de entrada, si queremos incluir cadena vacía la representamos con "."
alfabeto de la cinta
estado inicial
estados finales
número de cintas
transiciones de la forma: 
estado_actual simbolo_leido simbolo_leido_cinta_2 ... e_siguiente escribir_cinta1 movimiento_cinta1...

Asegurarse de no poner filas vacías al final del fichero y comprobar espacios

## Formato del fichero con las cadenas

cadena1
cadena2
....

## Explicación del código

Se tiene un fichero utils en el que se declaran todas las librerías externas, constantes y diferentes estructuras de datos y funciones de utilidad como split_string o las estructuras de datos simbol_movement
que representa un simbolo que se escribe en la cinta y el movimiento de la cabeza (derecha, izquierda o parar) y transition_info que guarda la información de una transición de la función de transición.

También tenemos la clase tape que representa una cinta infinita a ambos lados con los movimientos
tres movimientos. Se implementa mediante dos vectores y un entero current_pos que guarda la posición
de la cabeza en la cinta

La clase transtion_function guarda las transiciones mediante un vector de transition_function.
Tiene métodos para añadir transiciones y buscarlas

Finalmente la clase turing_machine que representa una máquina de turing multicinta, contiene un vector de tapes y un objeto transition_function donde se guarda toda la información de la especificación de la máquina en el constructor. El ámbito de las cintas es dentro de la función que analiza las cadenas,
para no tener que borrar y escribir continuamente las cintas cuando se quiera analizar una cadena nueva.
Finalmente el algoritmo para comprobar si una cadena pertenece al lenguaje es extremadamente simple, dado el estado actual y los símbolos leídos de las cintas comprueba en la función de transcición cual es el siguiente estado. Si no hay siguiente estado se para la máquina y se comprueba si el estado en el que paro es final.
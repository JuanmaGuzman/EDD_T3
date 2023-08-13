# Tarea 3 2023-1
# Tarea de Programación: Soluciones de Problemas NP-Hard, Grafos y Algoritmos Codiciosos

Esta tarea aborda diversos problemas relacionados con la implementación de algoritmos para resolver desafíos NP-Hard, manipulación de grafos y estrategias algorítmicas codiciosas. La tarea se divide en tres partes principales: búsqueda en mochila, generación de árboles de cobertura mínima y creación de memes humorísticos.

## Objetivos

- Desarrollar soluciones aproximadas para problemas NP-Hard.
- Aplicar técnicas algorítmicas en la manipulación de grafos.
- Utilizar estrategias algorítmicas codiciosas y de programación dinámica.

## Parte 1: Búsqueda en Mochila

En esta parte, el objetivo es resolver el problema de encontrar la mejor forma de repartir un conjunto de ítems en la menor cantidad de agentes posibles, respetando la capacidad máxima de carga de cada agente. El problema se aborda mediante técnicas de programación dinámica o codiciosas.

## Parte 2: Generación de Árboles de Cobertura Mínima

En la segunda parte, se aborda el problema de encontrar un árbol de cobertura mínima (Minimum Spanning Tree) en un grafo ponderado. Se busca también reducir la cantidad de aristas salientes de algunos nodos sin violar la propiedad de mínimo costo. Se requiere la construcción de un MST y la optimización de la cantidad de aristas por nodo.

## Parte 3: Creación de Memes

Se ofrece la oportunidad de ejercer la creatividad y el humor al generar memes relacionados con el curso. Los memes deben pertenecer a una de las tres categorías propuestas: meme con twist propio, chascarro de clases o chascarro favorito de la vida. Esta parte ofrece la posibilidad de obtener hasta 3 décimas adicionales.

## Ejecución

El programa se compila utilizando el comando `make` y se ejecuta con el siguiente comando:

```
./nombre_del_ejecutable input.txt output.txt
```

Donde `nombre_del_ejecutable` es el nombre del archivo ejecutable generado por la compilación. `input.txt` es el archivo de entrada que contiene la descripción del problema, y `output.txt` es el archivo donde se escribirán las respuestas generadas por el programa.

## Documento de Diseño

Se solicita un documento de diseño que incluya un análisis del enunciado, la planificación de la solución y un diagrama que represente la estructura y relaciones entre funciones y estructuras. Este documento no necesita ser formal, pero su presencia será considerada para la evaluación.

## Evaluación

La evaluación de esta tarea se realizará en función de la corrección y eficiencia de las soluciones implementadas, así como la calidad y coherencia del documento de diseño. Se proporcionarán puntajes parciales en función de los subóptimos alcanzados en la Parte 1 y la implementación correcta en la Parte 2. La creatividad y el humor serán evaluados en la Parte 3 de manera binaria (presente o no).

¡Esperamos que disfrutes abordando estos desafíos y demostrando tus habilidades en la resolución de problemas y en la creación de memes!
## Compilar

```
make
```

## Recompilar

```
make clean && make
```

## Ejecutar

Para la parte 1:
```
./mst input.txt output.txt
```

Para la parte 2:
```
./backpack input.txt output.txt
```

## Cápsulas
Te recomendamos ver [las cápsulas de DFS y priority queue](https://github.com/IIC2133-PUC/2022-2#material-complementario) para entender un poco mejor las tareas a realizar.

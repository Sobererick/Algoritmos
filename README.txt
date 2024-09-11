Hola estos son los codigos que use en la generacion del informe,cabe aclarar que hice algunas modificaciones con el fin de que los que no se tengan que usar distintos tipos de datos
igualmente deje la funcion original en caso de modificarla como comentario 


Instrucciones para el probar los algortimos:


Esta dividido en 3 

El generador de datos (c++)
El Archivo generador3.cpp es el encargado de generar los datasets para su posterior testeo 
para ejecutar este tiene que ser de la forma
1) g++ generador.cpp -o generador
2) ./generador

este programa es capaz de crear los datos necesario para probar en los algoritmos de ordenamiento y matrices
en el caso de los de ordenamiento se les da un nombre el cual dps se solicita ,para las matrices estan limitadas a un rango 100 y en lo posible recomendaria
que se testeara por debajo de los 100 para evitar error por numero muy grandes y estas se guardan como matriz_A.csv y matriz_B.csv.


El testeador de algoritmos (c++)

este ejecuta los codigo para su analisis,ademas proporciona el tiempo que tardo el algorimo en ms gracias a la libreria chrono de c++
para este implemente un makefile que se puede usar de la siguiente forma

1)make run
para compilar y ejecutar el codigo 
2)make clean 
en caso de que sea necesario borrarlo para hacer un cambio (error o cambio de archivo a probar)

El generador de graficos (python) que es necesario descargar el pip install matplotlib y ejecutarlo dps se va a desplegar un menu con las opcion para ver los graficos
con los datos posteriormente analizados


Los codigos fueron recolectados de las siguientes paginas(tuve que adaptar igualmente algunas partes para que se que funcionaran con los datasets)
https://www.geeksforgeeks.org/selection-sort-algorithm-2/

https://www.geeksforgeeks.org/quick-sort-algorithm/

https://www.geeksforgeeks.org/merge-sort/

https://www.geeksforgeeks.org/c-program-multiply-two-matrices/

El de matrices optimizadas tuve que hacerlo porque no encontraba uno similar para c++

https://www.geeksforgeeks.org/strassens-matrix-multiplication/


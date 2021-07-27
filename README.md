# sisop-tp2

Para correr el la simulación, se deberá hacer lo siguiente:

1. Luego de descomprimir el archivo zip, navegar en la consola hasta la carpeta resultante de la extracción y tipear en la consola 
    "make all"
    
2. Se generará una carpeta bin con los ejecutables.
3. Para incializar la simulación, navegar hasta la carpeta bin en la consola y tipear
    "./inicializa"
    
4. Ahora la simulación está iniciada con sus respectivas estructuras (semáforos, mutex, área compartida, etc).
5. Hay una cola generada donde se irá agregando nerds y serfs para que luego se suban a una balsa cuando ésta se pueda completar con las combinaciones válidas.
6. Si se quiere agregar un nerf a la cola, en la consola desde la carpeta bin tipear:
    "./nerds"
    
7. Si se quiere agregar un serf a la cola, en la consola desde la carpeta bin tipear:
    "./serfs"
    
8. Una vez que en la cola haya una combinación válida entre nerds y serfs, estos partirán en una balsa.
9. Si se quiere liberar el espacio utilizado por las estructuras de la simulación, desde la consola en el directorio bin tipear:
    "./libera"
    
10. Si se quiere finalizar la simulación, desde la consola en el directorio bin tipear:
    "./finaliza"

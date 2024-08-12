<p align=center>Программа <b>"Find in File"</b>.</p>

Программа для поиска в файле. Выделяет цветом совпадение, строку и количество вхождений.

<b>Linux:</b>

Для начала работы скопируйте репозиторий:
```
$ git clone https://github.com/rudikrudik/find_in_file.git
```
Перейдите в каталог с исходным кодом и скомпилируйте код:
```
$ g++ -o find_in_file main.cpp printLine.cpp readLine.cpp
```
Запустите приложение с параметрами "путь_до_файла" "паттерн_поиска" :
```
$ ./find_in_file path_to_file pattern_to_search
```

Результат работы программы:

![Иллюстрация к проекту](https://github.com/rudikrudik/find_in_file/blob/master/images/linux.jpg)

<b>Windows:</b>


![Иллюстрация к проекту](https://github.com/rudikrudik/find_in_file/blob/master/images/windows.jpg)









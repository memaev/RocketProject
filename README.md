# RocketProject
Программа для модулирования полета ракеты и построения графиков движения. Основной exe файл [rocket_project_calculations.exe](https://github.com/memaev/RocketProject/blob/main/rocket_project_calculations.exe), скомпилированный из C++ кода [rocket_project_calculations.cpp](https://github.com/memaev/RocketProject/blob/main/rocket_project_calculations.cpp) генерирует файл [output.txt](https://github.com/memaev/RocketProject/blob/main/output.txt) с данными t, x, y, Vx, Vy, которые обновляются каждые 0.0025 сек.

Далее с помощью скрипта [cmd.gpl](https://github.com/memaev/RocketProject/blob/main/cmd.gpl), написанного на gnuplot, генерерируются графики x(y), Vx(t), Vy(t), V(t), y(t). 

Pdf файл с формулами [main.pdf](https://github.com/memaev/RocketProject/blob/main/main.pdf) написан с помощью Latex ([pdfbuild.tex](https://github.com/memaev/RocketProject/blob/main/main.tex))

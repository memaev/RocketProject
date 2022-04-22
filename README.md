# RocketProject
Программа для модулирования полета ракеты и построения графиков движения. Основной exe файл [rocket_project_calculations.exe](RocketProject/rocket_project_calculations.exe), скомпилированный из C++ кода [rocket_project_calculations.cpp](RocketProject/rocket_project_calculations.cpp) генерирует файл [output.txt](RocketProject/output.txt) с данными t, x, y, Vx, Vy, которые обновляются каждые 0.0025 сек.

Далее с помощью скрипта [cmd.gpl](RocketProject/cmd.gpl), написанного на gnuplot, генерерируются графики x(y), Vx(t), Vy(t), V(t), y(t). 

Pdf файл с формулами [main.pdf](RocketProject/main.pdf) написан с помощью Latex ([pdfbuild.tex](RocketProject/main.tex))

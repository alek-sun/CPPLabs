Created by Fediaeva Irina
------------------------
Game "Life"

*Версия на русском*

Классы:

Driver 
Содержит шаблоны опций
Запускает интерактивный и автоматический режимы

====================== Parser ============================

ParseAll
Парсит коммандную строку и файл
Возвращает массив опций

Parser
Получает на вход массив незаполненных опций(без аргументов)
Возвращает массив заполненных опций

Descriptor
Содержит информацию об опции:
постоянное имя
возможные имена
описание
количесвто аргументов
тип аргументов

Option
Содержит Descriptor, информацию о том, заполнена опция или нет и массив аргументов(string, int), которые используются в зависимости от типа аргументов, содержащегося в Descriptor

ParseError
Класс исключений для парсера


====================== Loader ===========================
FileCondit
Получает состояние(Condition) из файла, используя Loader и Opener
  
Opener
Возвращает состояние, получая массив опций
Раскрывает команду SET, устанавливая состояние поля

Loader
Получает имя файла и возвращает массив заполненных опций 
Opener


======================== Game ===========================

CommandParser
Парсит команды интерактивного режима, принимает массив пустых опций

Condition
Содержит состояние и размеры поля, правила игры

InterMode
Содержит счетчик команд, и текущцю команду(Option).
Выполняет дейтсвия в завсисмости от неё, возвращает конечное состояние.

Setter
Устанавливает поле в нужное состояние принимая набор координат и значение, в которое нужно установить.
Возвращает поле, как массив int.

Stepper
Выполняет n шагов, содержит начальное состояние и кол-во шагов. 
Возвращает конечное состояние поля. 

====================== Export ========================

ConsExport
Принимает состояние, выводит его в консоль

FileExport
Принимает имя файла, состояние и выводит в него текущее состояние поля в том же формате, что у ввода

Для выхода из интерактивного режима используйте exit.


*Версия на английском*

Classes:

Driver
Contains option templates
Launches interactive and automatic modes

======================= Parser =========================== =

ParseAll
Parset command line and file
Returns an array of options

Parser
Gets an input of an array of empty options (no arguments)
Returns an array of filled options

Descriptor
Contains information about the option:
permanent name
possible names
description
number of arguments
argument type

Option
Contains a Descriptor, information about whether the option is filled or not and an array of arguments (string, int) that are used depending on the type of arguments contained in the Descriptor

ParseError
Parser exception class


====================== Loader ===========================
FileCondit
Gets the Condition from the file using Loader and Opener
  
Opener
Returns the state, getting an array of options
Opens the SET command, setting the field state

Loader
Gets the name of the file and returns an array of filled options
Opener


======================== Game ========================= ==

CommandParser
The interactive mode parsit takes an array of empty options

Condition
Contains the state and size of the field, the rules of the game

InterMode
Contains the command counter, and the current command (Option).
Performs deutsviya in zavisimosti from it, returns the final state.

Setter
Sets the field to the desired state by taking a set of coordinates and the value to which you want to set.
Returns the field as an int array.

Stepper
Performs n steps, contains the initial state and number of steps.
Returns the final state of the field.

======================= Export ========================

ConsExport
Accepts the state, outputs it to the console

FileExport
Accepts the name of the file, the state, and displays the current state of the field in the same format as the input

For exit from interactive mode use command "exit".
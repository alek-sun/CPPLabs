Created by Fediaeva Irina
------------------------
Game "Life"

*������ �� �������*

������:

Driver 
�������� ������� �����
��������� ������������� � �������������� ������

====================== Parser ============================

ParseAll
������ ���������� ������ � ����
���������� ������ �����

Parser
�������� �� ���� ������ ������������� �����(��� ����������)
���������� ������ ����������� �����

Descriptor
�������� ���������� �� �����:
���������� ���
��������� �����
��������
���������� ����������
��� ����������

Option
�������� Descriptor, ���������� � ���, ��������� ����� ��� ��� � ������ ����������(string, int), ������� ������������ � ����������� �� ���� ����������, ������������� � Descriptor

ParseError
����� ���������� ��� �������


====================== Loader ===========================
FileCondit
�������� ���������(Condition) �� �����, ��������� Loader � Opener
  
Opener
���������� ���������, ������� ������ �����
���������� ������� SET, ������������ ��������� ����

Loader
�������� ��� ����� � ���������� ������ ����������� ����� 
Opener


======================== Game ===========================

CommandParser
������ ������� �������������� ������, ��������� ������ ������ �����

Condition
�������� ��������� � ������� ����, ������� ����

InterMode
�������� ������� ������, � ������� �������(Option).
��������� �������� � ����������� �� ��, ���������� �������� ���������.

Setter
������������� ���� � ������ ��������� �������� ����� ��������� � ��������, � ������� ����� ����������.
���������� ����, ��� ������ int.

Stepper
��������� n �����, �������� ��������� ��������� � ���-�� �����. 
���������� �������� ��������� ����. 

====================== Export ========================

ConsExport
��������� ���������, ������� ��� � �������

FileExport
��������� ��� �����, ��������� � ������� � ���� ������� ��������� ���� � ��� �� �������, ��� � �����

��� ������ �� �������������� ������ ����������� exit.


*������ �� ����������*

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
��
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
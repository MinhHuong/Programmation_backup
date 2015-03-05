- Create the corresponding panel for other types of data (DataFlux, DataEco)

- REMEMBER : when using Database Simulator, I don't really have to write real shit, all I need is just some codes to make it work, and to understand the principle.
- ANOTHER  : without real Database, I use object and vector to save traces, but when I apply a database, I just have to save SQL INSTRUCTIONS, such as
"insert ... to..."'
"del...from..."
"update...set...where..."

Just that. And everything will be fine. 

- Some little bugs (not really bugs, but thay can cause a bit irritations to users) :
	+ If the button FIND ENTRY is pressed or date in the picker doesn't change, users can go to modification
	--> Until now the first condition is well realized, but the second isn't. I CANNOT find out how to notify changes of the value hold by jdatepicker, because I'm using a built-in app, so I seem to be unable to do any intervention to its structure.
	--> WAIT !!! Actually I CAN download the source code, edit some portions needed TO BE EDITED and build everything into a runnable jar again.
	
- Next step : connection to Database (VERY IMPORTANT AND I BET 150% EVERYTHING WILL MESSED UP)
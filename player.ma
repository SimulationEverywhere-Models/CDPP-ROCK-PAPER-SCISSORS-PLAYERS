[top]
components : requestReceiver@RequestReceiver
components : actionMaker@ActionMaker

in : in
out : out

Link : in in@requestReceiver
Link : out@requestReceiver in@actionMaker
Link : out@actionMaker out

[requestReceiver]
preparation : 00:00:01:000 

[actionMaker]
preparation : 00:00:00:500 
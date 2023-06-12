[top]
components : comparer@Comparer
components : Player1
components : Player2
out : out
in : in
Link : in playGame@comparer
Link : winReport@comparer out
Link : playGame1@comparer in@Player1
Link : playGame2@comparer in@Player2
Link : out@Player1 gameAction1@comparer
Link : out@Player2 gameAction2@comparer

[comparer]
preparation : 00:00:00:000 

[Player1]
components : requestReceiver1@RequestReceiver
components : actionMaker1@ActionMaker
in : in
out : out
Link : in in@requestReceiver1
Link : out@requestReceiver1 in@actionMaker1
Link : out@actionMaker1 out

[requestReceiver1]
preparation : 00:00:01:000 

[actionMaker1]
preparation : 00:00:00:500 

[Player2]
components : requestReceiver2@RequestReceiver
components : actionMaker2@ActionMaker
in : in
out : out
Link : in in@requestReceiver2
Link : out@requestReceiver2 in@actionMaker2
Link : out@actionMaker2 out

[requestReceiver2]
preparation : 00:00:01:000 

[actionMaker2]
preparation : 00:00:00:500 
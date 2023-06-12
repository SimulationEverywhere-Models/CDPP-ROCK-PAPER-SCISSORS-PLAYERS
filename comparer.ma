[top]
components : comparer@Comparer 
out : out1
out : out2
out : out3
in : in0
in : in1
in : in2
Link : in0 playGame@comparer
Link : in1 gameAction1@comparer
Link : in2 gameAction2@comparer
Link : playGame1@comparer out1
Link : playGame2@comparer out2
Link : winReport@comparer out3

[comparer]
preparation : 00:00:00:000 
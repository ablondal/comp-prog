# Done
num = input();

ns = num.split('.');
pre = ns[0];
if (len(ns)==1):
	post = "";
else: post = ns[1];

i = 0;
while i<len(pre) and pre[i] == '0':
	i += 1;
pre = pre[i:];

i = len(post);
while i>0 and post[i-1] == '0':
	i -= 1;
post = post[:i];

Eval = 0;

if len(pre)==0:
	i = 0;
	while i<len(post) and post[i] == '0':
		Eval -= 1;
		i += 1;
	post = post[i:];

	if len(post) == 0:
		pre = "0";
		Eval = 0;
	else:
		pre = post[0];
		post = post[1:];
		Eval -= 1;
else:
	i = len(pre)-1;
	Eval += i;
	post = pre[1:] + post;
	pre = pre[:1];

i = len(post);
while i>0 and post[i-1] == '0':
	i -= 1;
post = post[:i];

finstr = pre;
if len(post) != 0:
	finstr += "." + post;
if Eval != 0:
	finstr += "E" + str(Eval);
print(finstr)

set n=0
:flag1
start ./a.exe
set /a n+=1

if %n% ==10 exit
goto  flag1
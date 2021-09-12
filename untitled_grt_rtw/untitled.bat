
set MATLAB=C:\MATLAB\R2021a

cd .

if "%1"=="" ("C:\MATLAB\R2021a\bin\win64\gmake"  -f untitled.mk all) else ("C:\MATLAB\R2021a\bin\win64\gmake"  -f untitled.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1
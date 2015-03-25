echo "4 to 140 Calculation run"

write-host -nonewline "ARE YOU SURE? (Y/N) "
$response = read-host
if ( $response -ne "Y" ) { exit }

for($i=4; $i -le 140; $i += 2 ){
echo $i
&  ./SAPs4.exe $i
}
pause
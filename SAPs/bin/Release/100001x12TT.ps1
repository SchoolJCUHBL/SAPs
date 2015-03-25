echo "start 100001x12 SAP TORTURETEST"

write-host -nonewline "ARE YOU SURE? (Y/N) "
$response = read-host
if ( $response -ne "Y" ) { exit }

for($i=0; $i -le 100000; $i++ ){
echo $i
&  ./SAPs4.exe 12
}
pause
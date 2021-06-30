#!/bin/bash
ROOT_UID=0
SUCCESS=0

if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script..."
  exit $E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a eliminar..."
   exit 1
fi

# Del archivo con el listado de grupos a eliminar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo

eliminarGrupo(){
	eval nombre_grupo="$1"
	
	if grep -q $nombre_grupo /etc/group ;
	then
		groupdel "${nombre_grupo}"
		if [ $? -eq $SUCCESS ];
		then
			echo "Grupo [${nombre_grupo}] eliminado correctamente..."
		else
			echo "Grupo [${nombre_grupo}] no se pudo eliminar..."
		fi
	else
		echo "El grupo [${nombre_grupo}] no existe, no se puedo eliminar..."
	fi	
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}
exit 0

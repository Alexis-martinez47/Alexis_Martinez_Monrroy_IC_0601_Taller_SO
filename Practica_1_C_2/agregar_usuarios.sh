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

# Del archivo con el listado de usuarios a eliminar:
# Este es el formato:
# ejemplo:pass:123:1001:EJEMPLO:/home/ejemplo:/bin/bash:
#    |      |   |    |     |          |           |   
#    f1     f2  f3   f4    f5         f6          f7
# f1 = nombre_usuario
# f2 = contrasena
# f3 = usuario_id
# f4 = grupo_id
# f5 = comentario
# f6 = directorio
# f7 = terminal_de_comandos_a_usar

agregarUsuario(){
	eval usuario="$f1"
	eval contrasena="$f2"
	eval usuario_id="$f3"
	eval grupo_id="$f4"
	eval info="$f5"
	eval directorio="$f6"
	eval terminal="$f7"
	
	if grep -q $usuario /etc/passwd ;
	then
		echo "Ya hay un usuario con nombre [${usuario}], no se puede crear uno nuevo con el mismo nombre..."
	else
		if grep -q :x:$usuario_id /etc/passwd;
		then
			echo "Ya hay un usuario con ID [${usuario_id}], no se puede crear otro usuario con el mismo ID..."
		else
			if grep -q $grupo_id /etc/group;
			then
				useradd -p ${contrasena} -u ${usuario_id} -g ${grupo_id} -c ${info} -d ${directorio} -m -s ${terminal} ${usuario}
				echo "$usuario:$contrasena" | chpasswd --md5
				if [ $? -eq $SUCCESS ];
				then
					echo "Usuario [${usuario}] agregado correctamente..."
					chage -d0 ${usuario}
				else
					echo "Usuario [${usuario}] no se pudo agregar..."
				fi
			else
				echo "No existe un grupo con ID [${grupo_id}]..."
			fi
		fi
	fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	agregarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}" 
done < ${file}

exit 0

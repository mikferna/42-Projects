#!/bin/bash

# Iniciar el servicio de MariaDB
service mysql start 

# Crear el archivo SQL con las variables de entorno
cat <<EOF > db1.sql
CREATE DATABASE IF NOT EXISTS $db1_name;
CREATE USER IF NOT EXISTS '$db1_user'@'%' IDENTIFIED BY '$db1_pwd';
GRANT ALL PRIVILEGES ON $db1_name.* TO '$db1_user'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF

# Ejecutar el archivo SQL en MariaDB
mysql < db1.sql

# Detener el servicio de MariaDB
kill $(cat /var/run/mysqld/mysqld.pid)

# Iniciar MariaDB en modo demonio
mysqld

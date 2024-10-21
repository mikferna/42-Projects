FROM debian:buster


RUN apt update -y 

RUN apt install php-fpm php-mysql -y

RUN apt install curl -y


COPY ./tools/script.sh /
COPY ./tools/wp-cnf.php /


ENTRYPOINT ["sh", "/script.sh"]
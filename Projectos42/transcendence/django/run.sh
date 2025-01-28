#!/bin/sh

# Check if the directory exists
if [ ! -d "/code/django" ]; then
  echo "Directory /code/django does not exist"
  exit 1
fi

cd /code/django/mysite

# Check if manage.py exists
if [ ! -f "manage.py" ]; then
  echo "manage.py does not exist in /code/django"
  exit 1
fi

echo "from django.contrib.auth import get_user_model; User = get_user_model(); User.objects.create_superuser('admin', 'admin@gmail.com', 'admin') if not User.objects.filter(username='admin').exists() else None" | python manage.py shell

python manage.py makemigrations
python manage.py migrate

# Run the Django server
python manage.py runserver 0.0.0.0:8000
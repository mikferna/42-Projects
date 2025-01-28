from django.shortcuts import render
from .models import User

def index(request):
    print("Entró en la vista index")
    
    try:
        user = User.objects.create(name='Mikel', email='tontopolla@gmail.com', password='1234')
        print(f"Usuario creado: {user}")
    except Exception as e:
        print(f"Error al crear el usuario: {e}")
        
    return render(request, 'index.html')
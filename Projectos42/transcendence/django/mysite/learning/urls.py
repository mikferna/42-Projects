from django.urls import path
from . import views

urlpatterns = [
    path('mikel/', views.index, name='index'),
]
from django.contrib import admin
from django.urls import path
from django.views.generic import TemplateView
from client.views import ClientView

urlpatterns = [
    path('admin/', admin.site.urls),
    path('client/', ClientView.as_view(), name="client_view"),
]

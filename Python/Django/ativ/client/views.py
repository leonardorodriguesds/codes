from django.shortcuts import render
from django.views.generic import TemplateView

class ClientView(TemplateView):
    template_name = "client_view.html"
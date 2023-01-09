# -*- coding: utf-8 -*-
# settings.py

def init():
    # Global variables for cutechess command
    global main_command
    global main_config
    main_command = ''
    main_config = ''
    
    
    # Global variable for output (plots)
    global dataset 
    # dataset is a list of lists. Each list represents the values of an option.
    # the last list is the corresponding elo evaluated by cutechess
    dataset=list()
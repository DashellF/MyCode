import subprocess
import random
import string
import time

bad_output = target_output = r"""         
         _   _
        (q\_/p)
         /. .\         __
  ,__   =\_t_/=      .'o O'-.
     )   /   \      / O o_.-`|   
    (   ((   ))    /O_.-'  O |  
     \  /\) (/\    | o   o  o|   
      `-\  Y  /    |o   o O.-`  
         nn^nn     | O _.-'      
                   '--`         

munch...

         _   _
        (q\_/p)
         /. .\         __
  ,__   =\_t_/=      .'o O'-.
     )   /   \      / O o_.-`|   
    (   ((   ))      ).-'  O |  
     \  /\) (/\      )   o  o|   
      `-\  Y  /    |o   o O.-`  
         nn^nn     | O _.-'      
                   '--`         

munch...

         _   _
        (q\_/p)
         /. .\         __
  ,__   =\_t_/=      .'o O'-.
     )   /   \      / O o_.-`|   
    (   ((   ))        )'  O |  
     \  /\) (/\          )  o|   
      `-\  Y  /         ) O.-`  
         nn^nn        ) _.-'      
                   '--`         

MUNCH.............


         _   _
        (q\_/p)
         /.V.\        
  ,__   =\_t_/=   
     )   /   \      
    (   ((   ))   
     \  /\) (/\    
      `-\  Y  /    
         nn^nn        
                          

BLEHHHHH yuck. THAT'S not my cheese. GET OUT CLONE!!!1111!!!1!!!"""

def generate_random_hex_salt():
    return ''.join(random.choices(string.hexdigits.lower(), k=4))

def run_nc_command():
    process = subprocess.Popen(
        ['nc', 'verbal-sleep.picoctf.net', '58535'],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
    )
    

    process.stdin.write('g\n')
    

    process.stdin.write('Cheddar\n')
    

    hex_salt = generate_random_hex_salt()
    process.stdin.write(f'{hex_salt}\n')


    process.stdin.flush()


    output = process.stdout.read()
    return output

i = 1
while i == 1:
    output = run_nc_command()
    print("running")
    if bad_output not in output:
        print("FLAG FOUND!", output)
        break
    
    time.sleep(0.1)  # Wait for a second before sending the next set of commands
    i += 1
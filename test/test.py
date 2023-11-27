log = f"""
<|im_start|>system
hallo
<|im_end|>
"""

ask = "<|im_start|>assistant"

while True:
    inp = input()
    if (inp == 'exit'):
        break
    template = f"""
<|im_start|>user
{inp}
<|im_end|>
"""    
    log += template
    print("=======")
    print(log + ask)

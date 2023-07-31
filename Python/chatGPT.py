import openai
completion =openai.ChatCompletion.create(
    model="gpt-3.5-turbo",  
    message=[{"role":"user","content":"Tell the world about the chatGPT API in the style of a pirate."}]
    
)
print(completion)
import openai

# Set up your OpenAI API credentials
openai.api_key = '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'

# Generate a response from ChatGPT
response = openai.Completion.create(
    model="gpt-3.5-turbo",
    prompt="Hello, how are you?",
    max_tokens=50,
    n=1,
    stop=None,
    temperature=0.7
)


response = openai.Completion.create(
    model="gpt-3.5-turbo",
    messages=[
        {"role": "system", "content": "You are a helpful assistant."},
        {"role": "user", "content": "Who won the world series in 2020?"},
        {"role": "assistant", "content": "The Los Angeles Dodgers won the World Series in 2020."},
        {"role": "user", "content": "Where was it played?"}
    ]
)

reply = response.choices[0].message['content']
print("ChatGPT:", reply)


# Extract the generated reply from the API response
reply = response.choices[0].text.strip()

print("ChatGPT:", reply)

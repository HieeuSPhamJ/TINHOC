from operator import index
import discord
from discord.ext import commands
from discord.ext.commands import command, has_permissions, CheckFailure
import random
import asyncio
import math

intents = discord.Intents().default()
client = discord.Client()
client = commands.Bot(command_prefix='w!', case_insensitive=True)

@client.event
async def on_ready():
    print('We have logged in as {0.user}'
    .format(client))

@client.event
async def on_message(message):
    if message.author.bot: 
        return
    await client.process_commands(message)
    if message.content.startswith('gà') or message.content.startswith('Gà') or message.content.startswith('ưall gà') or message.content.startswith('Ưall gà') or message.content.startswith('<@!693084456449474620> gà') or message.content.startswith('chicken') :
        if message.content.startswith('<@!693084456449474620> gà'):
            await message.channel.send( f'{message.author.mention} <@!693084456449474620> vjp pro no1 <:wfthumbup:901446219145043979> ',mention_author = True)
        else: 
            await message.channel.send( f'{message.author.mention} gà 🐔 ',mention_author = True)
    # print(message.author.id) 

def is_Mod(user_id): 
    with open('id.txt', 'r') as f:
        if str(user_id) in f.read():
            return True
        else:
            return False

@client.command(name='say', pass_context=True)
async def say(ctx, *args):
    tu_ban_nhap=""
    if is_Mod(ctx.message.author.id) == True :
        for arg in args :
            tu_ban_nhap = str(tu_ban_nhap) + " " + arg    
        await ctx.send(tu_ban_nhap)
        await ctx.message.delete()
    else:  
        await ctx.send(f' {ctx.author.mention} gà thế này sao được sài bot 🐔'  , mention_author = True)

token = ""
with open("token.txt") as file:
    token = file.read()

client.run(token)    
import pandas as pd
import plotly.express as px

s=input()

df = pd.read_csv('./graph_csv/'+s+'.csv')

fig = px.line(df,x='Date',y='Rating',
    title='Toilet Scuffle -- '+s)
fig.write_html('./'+s+'/index.html')

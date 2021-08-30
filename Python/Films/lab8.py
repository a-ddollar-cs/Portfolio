#!/usr/bin/python3.5
import pandas as pd


fields = ['Year', 'Length', 'Title', 'Director']
film = pd.read_csv('Films.csv',skipinitialspace=True, usecols=fields, encoding = "ISO-8859-1")


fields2 = [ 'Year', 'Length', 'Title', 'budget', 'rating', 'Action', 'Animation', 'Comedy', 'Drama', 'Documentary', 'Romance', 'Short']
movies = pd.read_csv('Movies.csv',skipinitialspace=True, usecols=fields2, encoding = "ISO-8859-1")


FilmMovies = pd.merge(film,movies,on=['Year', 'Length', 'Title'])


FilmMovies = FilmMovies.drop_duplicates(subset=['Title'])
FilmMovies = FilmMovies.dropna(subset=['budget'])

print(FilmMovies)

FM_title = FilmMovies.set_index('Title').T.to_dict('list')


tKey = input("Enter Movie Title here: ")

print(FM_title.get(tKey, "Movie not in database"))
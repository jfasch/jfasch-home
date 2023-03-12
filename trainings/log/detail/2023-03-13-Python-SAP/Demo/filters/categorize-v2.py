import stuff.category              # <-- use code from stuff/category.py

def transform(data):
    data['category'] = data['info'].apply(stuff.category.categorize)
    return data

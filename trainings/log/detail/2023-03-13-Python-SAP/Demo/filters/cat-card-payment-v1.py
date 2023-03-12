def transform(data):
    data['category'] = data['info'].str.startswith('Bezahlung Karte')
    return data

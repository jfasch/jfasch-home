def categorize(info):
    if info.startswith('Bezahlung Karte'):
        return 'card-payment'
    else:
        return 'unknown'

def transform(data):
    data['category'] = data['info'].apply(categorize)
    return data

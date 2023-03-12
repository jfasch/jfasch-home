def categorize(info):
    if info.startswith('Bezahlung Karte'):
        return categorize_card_payment(info)
    return 'unknown'

def categorize_card_payment(info):
    fields = info.split('|')
    which = fields[0]
    pos = fields[1]
    company = fields[2]

    if company.startswith('SPAR DANKT'):
        return 'living'
    if company.startswith('JET'):
        return 'car'

    return 'card-unknown'


def transform(data):
    data['category'] = data['info'].apply(categorize)
    return data

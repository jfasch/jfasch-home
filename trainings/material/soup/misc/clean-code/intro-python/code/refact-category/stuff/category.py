from enum import Enum

def categorize(df):
    df['category'] = df['info'].apply(lambda cat: str_category(category(cat)))
    return df

Category = Enum('Category', ('Goingout', 'Living', 'Sport', 'Car', 'CardUnknown', 'Unknown'))

def str_category(cat):
    match cat:
        case Category.Goingout: return "goingout"
        case Category.Living: return "living"
        case Category.Sport: return "sport"
        case Category.Car: return "Car"
        case Category.CardUnknown: return "card-unknown"
        case Category.Unknown: return "unknown"
        case _: assert False

def category(info):
    if info.startswith('Bezahlung Karte'):
        which, terminal, organization = info.split('|')
        
        if organization.startswith('ORPHEUM BAR'):
            return Category.Goingout
        if organization.startswith('BILLA DANKT'):
            return Category.Living
        if organization.startswith('SPAR DANKT'):
            return Category.Living
        if organization.startswith('HERVIS'):
            return Category.Sport
        if organization.startswith('SHELL'):
            return Category.Car
        if organization.startswith('FLUGHAFEN WIEN'):
            return Category.Car
        return Category.CardUnknown
    else:
        return Category.Unknown


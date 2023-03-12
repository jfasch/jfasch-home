def transform(data):
    filt_uncat = data['category'] == 'unknown'
    uncat_rows = data.loc[filt_uncat]

    return uncat_rows

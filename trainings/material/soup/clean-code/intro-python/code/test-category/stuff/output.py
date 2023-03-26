def write_to_csv(df, csvname):
    df.to_csv(
        csvname,
        sep=';', encoding='iso-8859-1',
        index=False,
    )


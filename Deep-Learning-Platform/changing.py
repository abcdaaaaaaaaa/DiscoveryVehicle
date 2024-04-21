    parser.add_argument('--no-trace', action='store_false', help='don`t trace model')

    with torch.no_grad():
        detect()

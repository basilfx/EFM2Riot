def only_for_board(boards):
    """
    Create a filter that is only considered when the given board matches.
    """

    def _inner(context):
        return context["board"] in boards
    return _inner


def only_for_development():
    """
    Create a filter that is only considered when development is toggled.
    """

    def _inner(context):
        return context["development"]
    return _inner


def only_for_board_and_development(boards):
    """
    Create a filter that is only considered when the given board matches and
    when development is toggled.
    """

    def _inner(context):
        return context["board"] in boards and context["development"]
    return _inner


def never():
    """
    Create a filter that returns False.
    """

    def _inner(context):
        return False
    return _inner

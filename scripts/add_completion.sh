_add_completion()
{
    # Pointer to current completion word
    local cur
    # Array to store possible completions
    COMPREPLY=()

    cur=${COMP_WORDS[COMP_CWORD]}
    case "$cur" in
    -*)
    COMPREPLY=( $( compgen -W '-h -d -n -l --help --display \
                               --name= --language=' -- $cur ) );;
    esac

    if [[ ! "${COMPREPLY[@]}" =~ "=" ]]; then
        compopt +o nospace
    fi

    return 0
}

complete -F _add_completion -o nospace aqua-template

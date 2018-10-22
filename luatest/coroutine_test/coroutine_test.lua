function receive(prod)
    local status, value = coroutine.resume(prod)
    return value
end

function send(x)
    coroutine.yield(x)
end

function producer()
    return coroutine.create(function()
        while true do
            local x = io.read()
            send(x)
        end
    end)
end

function filter(prod)
    return coroutine.create(function()
        local line = 1
        while true do
            local x = receive(prod)
            x = string.format('%5d %s', line, x)
            send(x)
            line = line + 1
        end
    end)
end

function consumer(prod)
    while true do
        local x = receive(prod) -- get new value
        io.write(x, '\n') -- consume new value
    end
end

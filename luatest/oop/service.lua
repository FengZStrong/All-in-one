local service = {}

function service:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self

    return o
end

function service:call(callee)
    print('call ' .. callee)
end

return service

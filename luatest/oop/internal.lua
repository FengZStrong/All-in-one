local service = require('service')

local internal = service:new()

function internal:call(callee)
    print('internal call ' .. callee)
end

return internal

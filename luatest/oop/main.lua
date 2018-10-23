local service = require('service')
local internal = require('internal')

s = internal:new()
s1 = service:new()
s:call('10086')
s1:call('10010')

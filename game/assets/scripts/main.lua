function purp.start()
    purp.clientlog.info("Hello From lua, Lua has started")
end

function purp.update(dt)
    purp.clientlog.trace("dt = " .. dt)
end

function purp.onevent(e)
    if e.type == purp.event.WindowResize then
        purp.clientlog.info("Resize event received")
        e.handled = true
    end
end

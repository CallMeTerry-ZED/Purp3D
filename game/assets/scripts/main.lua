function purp.start()
    purp.clientlog.info("Hello From lua, Lua has started")
end

function purp.update(dt)
    if purp.input.is_key_pressed(purp.key.TAB) then
        purp.clientlog.info("TAB is held down (poll)")
    end

    if purp.input.is_mouse_button_pressed(purp.mouse.LEFT) then
        local pos = purp.input.get_mouse_position()
        purp.clientlog.info(string.format("Mouse LMB at %.1f %.1f", pos.x, pos.y))
    end
end

function purp.onevent(e)
    if e.type == purp.event.KeyPressed then
        purp.clientlog.info("Key pressed: " .. e.keycode)

        if e.keycode == purp.key.TAB then
            purp.clientlog.info("TAB pressed via event")
        end

        e.handled = true
    end

    if e.type == purp.event.MouseMoved then
        purp.clientlog.info(
            string.format("Mouse moved: %.1f %.1f", e.mouse_x, e.mouse_y)
        )
    end

    if e.type == purp.event.WindowResize then
        purp.clientlog.info(
            string.format("Window resized: %dx%d", e.width, e.height)
        )
    end
end
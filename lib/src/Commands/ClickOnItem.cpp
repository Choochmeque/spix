/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "ClickOnItem.h"

#include <Scene/Scene.h>

namespace uibot {
namespace cmd {

ClickOnItem::ClickOnItem(ItemPath path, bool press, bool release)
: m_path(std::move(path))
, m_press(press)
, m_release(release)
{
}

void ClickOnItem::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (!item) {
        env.state().reportError("ClickOnItem: Item not found: " + m_path.string());
        return;
    }

    auto size = item->size();
    Point midPoint(size.width / 2.0, size.height / 2.0);
    env.scene().events().mouseClick(item.get(), midPoint, m_press, m_release);
}

} // namespace cmd
} // namespace uibot
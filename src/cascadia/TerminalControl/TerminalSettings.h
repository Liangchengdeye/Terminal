#pragma once

#include "TerminalSettings.g.h"
#include "../../cascadia/TerminalCore/Settings.h"

namespace winrt::Microsoft::Terminal::TerminalControl::implementation
{
    // Implements ::Microsoft::Terminal::Core::ITerminalSettings to make sure that the
    // winrt::Microsoft::Terminal::TerminalControl::ITerminalSettings and
    // ITerminalSettings stay in sync
    struct TerminalSettings : TerminalSettingsT<TerminalSettings>,
                              public ::Microsoft::Terminal::Core::ITerminalSettings
    {
        TerminalSettings();

    public:
        // --------------------------- Core Settings ---------------------------
        //  All of these settings are defined in ITerminalSettings.
        //  They should also all be properties in TerminalSettings.idl
        uint32_t DefaultForeground() const noexcept override;
        void DefaultForeground(uint32_t value) override;
        uint32_t DefaultBackground() const noexcept override;
        void DefaultBackground(uint32_t value) override;

        std::basic_string_view<uint32_t> GetColorTable() const noexcept override;
        void SetColorTable(std::basic_string_view<uint32_t const> value) override;

        uint32_t GetColorTableEntry(int32_t index);
        void SetColorTableEntry(int32_t index, uint32_t value);

        int32_t HistorySize() const noexcept override;
        void HistorySize(int32_t value) override;
        int32_t InitialRows() const noexcept override;
        void InitialRows(int32_t value) override;
        int32_t InitialCols() const noexcept override;
        void InitialCols(int32_t value) override;

        bool SnapOnInput() const noexcept override;
        void SnapOnInput(bool value) override;
        // ------------------------ End of Core Settings -----------------------

        bool UseAcrylic() const noexcept;
        void UseAcrylic(bool value);
        double TintOpacity() const noexcept;
        void TintOpacity(double value);

        hstring FontFace() const noexcept;
        void FontFace(hstring const& value);
        int32_t FontSize() const noexcept;
        void FontSize(int32_t value);

        TerminalControl::IKeyBindings KeyBindings();
        void KeyBindings(TerminalControl::IKeyBindings const& value);

        hstring Commandline() const noexcept;
        void Commandline(hstring const& value);

        hstring WorkingDirectory() const noexcept;
        void WorkingDirectory(hstring const& value);

        hstring EnvironmentVariables() const noexcept;
        void EnvironmentVariables(hstring const& value);

    private:
        // NOTE: If you add more settings to ITerminalSettings, you must also
        //      make sure to connect them to the terminal settings in
        //      TermControl::s_MakeCoreSettings
        ::Microsoft::Terminal::Core::Settings _settings;

        bool _useAcrylic;
        double _tintOpacity;
        hstring _fontFace;
        int32_t _fontSize;
        hstring _commandline;
        hstring _workingDir;
        hstring _envVars;
        TerminalControl::IKeyBindings _keyBindings;
    };
}

namespace winrt::Microsoft::Terminal::TerminalControl::factory_implementation
{
    struct TerminalSettings : TerminalSettingsT<TerminalSettings, implementation::TerminalSettings>
    {
    };
}
